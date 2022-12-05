import React from 'react';
import './App.css';
import Footer from './components/Footer';
import ContentRow from './components/ContentRow';

import Navbar from './components/Navbar';

function App() {
	return (
		<div>
			<Navbar />
			<main className="py-5 px-3 min-vh-100">
				<ContentRow seed={1} />
				<ContentRow
					seed={2}
					reverse={true}
				/>
				<ContentRow seed={3} />
				<ContentRow
					seed={4}
					reverse={true}
				/>
			</main>
			<Footer />
		</div>
	);
}

export default App;
